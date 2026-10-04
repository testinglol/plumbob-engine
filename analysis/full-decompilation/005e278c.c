
undefined4 __thiscall
FUN_005e278c(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  char cVar1;
  
  if ((((char)param_1[1] == '\0') && (param_2 != 0)) && (param_3 != 0)) {
    param_1[8] = param_3;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = param_2;
    param_1[2] = param_4;
    param_1[3] = param_5;
    param_1[4] = param_6;
    param_1[0x10] = param_7;
    param_1[0x11] = param_8;
    cVar1 = (**(code **)(*param_1 + 0xdc))();
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 1) = 1;
      return 1;
    }
  }
  return 0;
}

