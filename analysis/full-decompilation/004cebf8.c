
void __thiscall FUN_004cebf8(int param_1,int param_2,char param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 8) == param_2) && (param_3 == '\0')) {
    return;
  }
  if (*(int *)(param_1 + 8) == 4) {
    *(undefined1 *)(*(int *)(DAT_006e486c + 4) + 0x4c0) = 0;
  }
  if ((*(int *)(param_1 + 8) != 2) && (param_2 == 2)) {
    FUN_0041652a();
    FUN_0043e0a9();
    uVar3 = DAT_006e5490;
    thunk_FUN_005847fc(DAT_006e5490);
    FUN_005a0410(uVar3);
    FUN_004072c7();
  }
  if ((param_2 == 0) || (param_2 == 1)) {
    FUN_004cf169(0,0);
  }
  if (((*(int *)(param_1 + 8) != 2) && (*(int *)(DAT_006e486c + 0x18) != 0)) &&
     (*(int *)(DAT_006e486c + 0x18) != -8)) {
    FUN_004935a1();
  }
  if (((*(int *)(param_1 + 8) == 0) || (param_2 == 0)) && (*(int *)(param_1 + 0x1f0) != 0)) {
    FUN_004b0de0();
  }
  *(int *)(param_1 + 8) = param_2;
  if (param_2 == 0) {
    FUN_004cf268(*(undefined4 *)(param_1 + 0x68));
    FUN_004d3356(1,1);
    pcVar2 = s_Entering_Build_Mode_006c7b40;
  }
  else if (param_2 == 1) {
    if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 1) {
      cVar1 = FUN_004074f7();
      if (cVar1 == '\x01') {
        *(undefined4 *)(param_1 + 0xa0) = 2;
      }
      else {
        cVar1 = FUN_00407525();
        if (cVar1 == '\x01') {
          *(undefined4 *)(param_1 + 0xa0) = 3;
        }
        else {
          cVar1 = FUN_004ce974();
          if (cVar1 == '\x01') {
            *(undefined4 *)(param_1 + 0xa0) = 4;
          }
          else {
            cVar1 = FUN_0040750e();
            if (cVar1 == '\x01') {
              *(undefined4 *)(param_1 + 0xa0) = 5;
            }
            else {
              cVar1 = FUN_0042886f();
              if (cVar1 != '\x01') {
                FUN_004ce994();
                goto LAB_004ced8f;
              }
              *(undefined4 *)(param_1 + 0xa0) = 6;
            }
          }
        }
      }
    }
    else {
LAB_004ced8f:
      *(undefined4 *)(param_1 + 0xa0) = 1;
    }
    *(undefined4 *)(param_1 + 0xa4) = 0;
    FUN_004cf579();
    FUN_004cf4ff(*(undefined4 *)(param_1 + 0x9c));
    FUN_004d3356(1,1);
    pcVar2 = s_Entering_Buy_Mode_006c7b2c;
  }
  else if (param_2 == 2) {
    FUN_004cf136(6,0);
    FUN_004d3356(*(undefined1 *)(param_1 + 0x40),0);
    if ((*(int *)(DAT_006f2a08 + 0x90) != 0) && (*(char *)(DAT_006f2a08 + 0xf5) == '\0'))
    goto LAB_004cee5d;
    pcVar2 = s_Entering_Live_Mode_006c7b18;
  }
  else if (param_2 == 4) {
    FUN_004cf169(0,0);
    FUN_004cfe14(0,0);
    FUN_004d3356(1,1);
    pcVar2 = s_Entering_Camera_Mode_006c7b00;
  }
  else {
    FUN_004cf169(0,0);
    FUN_004d3356(1,0);
    pcVar2 = s_Entering_Options_Mode_006c7ae8;
  }
  FUN_004df9a5(pcVar2);
LAB_004cee5d:
  if (DAT_006e5780 != '\0') {
    FUN_0040766a(0x91,0);
    DAT_006e5780 = '\0';
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0xfff7ffbf;
  return;
}

