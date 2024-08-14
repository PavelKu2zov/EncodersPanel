rotations = ['Right', 'Left']
sw11_pos = ['SW11_pos1', 'SW11_pos2', 'SW11_pos3']
sw8_pos = ['SW8_pos1', 'SW8_pos2',]
button = ['button_OFF', 'button_ON']
button_a = ['button_A_OFF', 'button_A_ON']
button_b = ['button_B_OFF', 'button_B_ON']


cc_default = 0
data_default = 0
cnt = 0

# gen = 'SW7'
# gen = 'SW9'
# gen = 'SW10'
# gen = 'SW7'
gen = 'SW1'

if gen == 'SW7':
    for item_sw11 in sw11_pos:
        for but_b_state in button_b:
            for but_a_state in button_a:
                for item_sw8 in sw8_pos:
                    for item_rotation in rotations:
                        print(f'#define CONTROL_ENCODER_SW7_VAR{cnt}_CC   ({cc_default}) // {item_rotation}, {item_sw11}, {item_sw8}, {but_b_state}, {but_a_state}')
                        print(f'#define CONTROL_ENCODER_SW7_VAR{cnt}_DATA ({data_default})')
                        cc_default+=1
                        data_default+=1
                        cnt+=1
elif gen == 'SW9':
    for item_sw11 in sw11_pos:
        for but_b_state in button_b:
            for but_a_state in button_a:
                for item_sw8 in sw8_pos:
                    for item_rotation in rotations:
                        print(f'#define CONTROL_ENCODER_SW9_VAR{cnt}_CC   ({cc_default}) // {item_rotation}, {item_sw11}, {item_sw8}, {but_b_state}, {but_a_state}')
                        print(f'#define CONTROL_ENCODER_SW9_VAR{cnt}_DATA ({data_default})')
                        cc_default+=1
                        data_default+=1
                        cnt+=1
elif gen == 'SW10':
    for item_sw11 in sw11_pos:
        for but_b_state in button_b:
            for but_a_state in button_a:
                for item_sw8 in sw8_pos:
                    for item_rotation in rotations:
                        print(f'#define CONTROL_ENCODER_SW10_VAR{cnt}_CC   ({cc_default}) // {item_rotation}, {item_sw11}, {item_sw8}, {but_b_state}, {but_a_state}')
                        print(f'#define CONTROL_ENCODER_SW10_VAR{cnt}_DATA ({data_default})')
                        cc_default+=1
                        data_default+=1
                        cnt+=1

elif gen == 'SW1':
    for index in range(1, 7):
        for item_sw11 in sw11_pos:
            for item_sw8 in sw8_pos:
                for but_b_state in button_b:
                    for but_a_state in button_a:
                        print(f'#define CONTROL_ENCODER_SW{index}_VAR{cnt}_CC   ({cc_default}) // {item_sw11}, {item_sw8},  {but_b_state}, {but_a_state}')
                        print(f'#define CONTROL_ENCODER_SW{index}_VAR{cnt}_DATA ({data_default})')
                        cc_default+=1
                        data_default+=1
                        cnt+=1
        print()
        cnt=0
        cc_default = 0
        data_default = 0