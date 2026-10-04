
void __fastcall FUN_004357f6(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  if (*(short *)(param_1[0x46] + 0x14) == 0) {
    FUN_00422d79(0xc,0,0);
    iVar4 = (param_1[0x4d] - param_1[0x4c]) / 0x24 + -1;
    if (0 < iVar4) {
      iVar3 = 0x24;
      do {
        if ((iVar3 < 0x24) || ((param_1[0x4d] - param_1[0x4c]) / 0x24 + -1 <= iVar2)) {
          iVar1 = 0;
        }
        else {
          iVar1 = param_1[0x4c] + iVar3;
        }
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_00407498((int)*(short *)(iVar1 + 0x10));
        }
        if (iVar1 != 0) {
          if ((iVar3 < 0x24) || ((param_1[0x4d] - param_1[0x4c]) / 0x24 + -1 <= iVar2)) {
            iVar1 = 0;
          }
          else {
            iVar1 = param_1[0x4c] + iVar3;
          }
          if (iVar1 != 0) {
            FUN_00407498((int)*(short *)(iVar1 + 0x10));
          }
          FUN_00422d79(0xc,0,0);
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x24;
      } while (iVar2 < iVar4);
    }
  }
  (**(code **)(*param_1 + 0x50))(1);
  return;
}

