#!/usr/bin/python3.10

import serial
import sys
import re
import crc
from xmodem import XMODEM
from time import sleep

#define CONTROL_ENCODER_SW7_VAR4_CC    (2) // Right, SW11_pos1, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW7_VAR4_DATA  (65)
var = ['CC', 'DATA']

sw7_prm = {"SW7": [f'VAR{i}_{j}' for i in range(0, 24) for j in var]}
sw9_prm = {"SW9": [f'VAR{i}_{j}' for i in range(0, 12) for j in var]}
sw10_prm = {"SW10": [f'VAR{i}_{j}' for i in range(0, 12) for j in var]}
sw1_prm = {"SW1": [f'VAR{i}_{j}' for i in range(0, 6) for j in var]}
sw2_prm = {"SW2": [f'VAR{i}_{j}' for i in range(0, 6) for j in var]}
sw3_prm = {"SW3": [f'VAR{i}_{j}' for i in range(0, 6) for j in var]}
sw4_prm = {"SW4": [f'VAR{i}_{j}' for i in range(0, 6) for j in var]}
sw5_prm = {"SW5": [f'VAR{i}_{j}' for i in range(0, 6) for j in var]}
sw6_prm = {"SW6": [f'VAR{i}_{j}' for i in range(0, 6) for j in var]}

prm_list = [sw7_prm, sw9_prm, sw10_prm, sw1_prm, sw2_prm, sw3_prm, sw4_prm, sw5_prm, sw6_prm]

s = serial.Serial(port='/dev/ttyUSB0', baudrate=115200, bytesize=8, parity='N', stopbits=1, timeout=None, xonxoff=0, rtscts=0)


def get_prm(sw_num, var_num, data_in):
	for line in data_in:
		if f'CONTROL_ENCODER_{sw_num}' in line and f'_{var_num}' in line:
			# print(line)
			match = re.findall(r'#define.+CONTROL_ENCODER_SW.+\((\d+)\)', line)
			if len(match) > 0:
				# print(match[0])
				return int(match[0])
			else:
				print(f'ERROR: wrong cfg file format in "{line}"')
				exit(1)

def getc(size, timeout=1):
	return s.read(size)

def putc(data, timeout=1):
	s.write(data)

def upload():
	print("Upload panel configurations")
	data_out = bytearray()
	with open(sys.argv[1], 'r') as f, open('panel_cfg.bin', 'wb+') as f_out:
		data_cfg = f.read()
		for item in prm_list:
			sw, params = list(item.items())[0]
			for prm in params:
				b = get_prm(sw, prm, data_cfg.split('\n'))
				f_out.write(b.to_bytes(1, 'big'))
				data_out.append(b)
		cal_crc = crc.ExpsasCRC.calculate_pmc_crc32(data_out)
		print(hex(cal_crc))
		print(cal_crc.to_bytes(4, 'big'))
		data_out = b''.join([data_out, cal_crc.to_bytes(4, 'big')])
		print(data_out)
		f_out.write(cal_crc.to_bytes(4, 'little'))

		# s.open()
		modem = XMODEM(getc, putc)
		# f = open('file.txt', 'rb')
		s.write(b'u')
		f_out.seek(0)
		# write len
		payload = f_out.read()
		len_payload = len(payload) - 4
		print(f'Len payload: {len_payload}')
		f_out.seek(0)
		f_out.write(len_payload.to_bytes(2, 'big'))
		f_out.write(payload)
		f_out.seek(0)
		print(modem.send(f_out))
		s.close()

if __name__ == "__main__":
	upload()