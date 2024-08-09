rotations = ['Left', 'Right']
sw11_pos = ['SW11_pos1','SW11_pos2', 'SW11_pos3']
sw8_pos = ['SW8_pos1', 'SW8_pos2',]
button = ['button_ON', 'button_OFF']

cc_default = 10
data_default = 20
cnt = 0

# gen = 'SW7'
# gen = 'SW9'
# gen = 'SW10'
gen = 'SW1'

if gen == 'SW7':
    for item_button in button:
        for item_sw8 in sw8_pos:
            for item_sw11 in sw11_pos:  
                for item_rotation in rotations:
                    print(f'#define CONTROL_ENCODER_SW7_VAR{cnt}_CC ({cc_default}) // {item_rotation}, {item_sw11}, {item_sw8}, {item_button}')
                    print(f'#define CONTROL_ENCODER_SW7_VAR{cnt}_DATA ({data_default})')
                    cnt+=1
elif gen == 'SW9':
    for item_sw8 in sw8_pos:
        for item_sw11 in sw11_pos:  
            for item_rotation in rotations:
                print(f'#define CONTROL_ENCODER_SW9_VAR{cnt}_CC ({cc_default}) // {item_rotation}, {item_sw11}, {item_sw8}')
                print(f'#define CONTROL_ENCODER_SW9_VAR{cnt}_DATA ({data_default})')
                cnt+=1

elif gen == 'SW10':
    for item_sw8 in sw8_pos:
        for item_sw11 in sw11_pos:  
            for item_rotation in rotations:
                print(f'#define CONTROL_ENCODER_SW10_VAR{cnt}_CC ({cc_default}) // {item_rotation}, {item_sw11}, {item_sw8}')
                print(f'#define CONTROL_ENCODER_SW10_VAR{cnt}_DATA ({data_default})')
                cnt+=1

elif gen == 'SW1':
    for index in range(0,7):
        for item_sw11 in sw11_pos:
            for item_sw8 in sw8_pos:  
                print(f'#define CONTROL_ENCODER_SW{index}_VAR{cnt}_CC ({cc_default}) // {item_sw11}, {item_sw8}')
                print(f'#define CONTROL_ENCODER_SW{index}_VAR{cnt}_DATA ({data_default})')
                cnt+=1
        print()
        cnt=0