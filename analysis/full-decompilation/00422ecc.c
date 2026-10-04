
void __thiscall
FUN_00422ecc(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_004356d4(param_2,param_3,param_4,param_5);
  iVar3 = *(int *)(param_1 + 400);
  if (iVar3 != 0) goto LAB_00422f00;
  while (iVar3 = param_1, iVar3 != 0) {
LAB_00422f00:
    FUN_00422d79(0xb,0,0);
    param_4 = 0;
    iVar4 = (*(int *)(iVar3 + 0x134) - *(int *)(iVar3 + 0x130)) / 0x24 + -1;
    if (0 < iVar4) {
      param_5 = 0x24;
      do {
        if ((param_5 < 0x24) ||
           ((*(int *)(iVar3 + 0x134) - *(int *)(iVar3 + 0x130)) / 0x24 + -1 <= param_4)) {
          iVar2 = 0;
        }
        else {
          iVar2 = param_5 + *(int *)(iVar3 + 0x130);
        }
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_00407498((int)*(short *)(iVar2 + 0x10));
        }
        if (iVar2 != 0) {
          if ((param_5 < 0x24) ||
             ((*(int *)(iVar3 + 0x134) - *(int *)(iVar3 + 0x130)) / 0x24 + -1 <= param_4)) {
            iVar2 = 0;
          }
          else {
            iVar2 = param_5 + *(int *)(iVar3 + 0x130);
          }
          if (iVar2 != 0) {
            FUN_00407498((int)*(short *)(iVar2 + 0x10));
          }
          FUN_00422d79(0xb,0,0);
        }
        param_4 = param_4 + 1;
        param_5 = param_5 + 0x24;
      } while (param_4 < iVar4);
    }
    param_1 = *(int *)(iVar3 + 0x18c);
  }
  cVar1 = FUN_00423481();
  if (cVar1 != '\0') {
    FUN_00423621();
  }
  return;
}

