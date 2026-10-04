
int __thiscall
FUN_004c8148(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 *param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined1 param_11,undefined4 param_12)

{
  FUN_004c783e(param_3,param_2,param_4,param_5,param_6,param_8,param_9,param_10,param_11,1);
  *(undefined4 *)(param_1 + 0x38) = *param_7;
  *(undefined4 *)(param_1 + 0x3c) = param_7[1];
  *(undefined4 *)(param_1 + 0x40) = param_12;
  FUN_004643bc((undefined4 *)(param_1 + 0x38),*(short *)(param_1 + 10) - *(short *)(param_1 + 0x3a),
               *(short *)(param_1 + 0xc) - *(short *)(param_1 + 0x3c));
  *(undefined4 *)(param_1 + 0x44) = 0;
  return param_1;
}

