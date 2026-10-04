
void __thiscall
FUN_004356d4(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  (**(code **)(*param_1 + 0x58))(param_2,param_3,param_4,param_5,1);
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*param_1 + 0x2c))();
    (**(code **)(*piVar2 + 0x20))(1);
  }
  if (*(short *)(param_1[0x46] + 0x14) == 0) {
    FUN_00422d79(0xb,0,0);
    param_4 = 0;
    iVar1 = (param_1[0x4d] - param_1[0x4c]) / 0x24 + -1;
    if (0 < iVar1) {
      param_5 = 0x24;
      do {
        if ((param_5 < 0x24) || ((param_1[0x4d] - param_1[0x4c]) / 0x24 + -1 <= param_4)) {
          iVar3 = 0;
        }
        else {
          iVar3 = param_5 + param_1[0x4c];
        }
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_00407498((int)*(short *)(iVar3 + 0x10));
        }
        if (iVar3 != 0) {
          if ((param_5 < 0x24) || ((param_1[0x4d] - param_1[0x4c]) / 0x24 + -1 <= param_4)) {
            iVar3 = 0;
          }
          else {
            iVar3 = param_5 + param_1[0x4c];
          }
          if (iVar3 != 0) {
            FUN_00407498((int)*(short *)(iVar3 + 0x10));
          }
          FUN_00422d79(0xb,0,0);
        }
        param_4 = param_4 + 1;
        param_5 = param_5 + 0x24;
      } while (param_4 < iVar1);
    }
  }
  return;
}

