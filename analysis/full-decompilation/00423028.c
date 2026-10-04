
void __thiscall FUN_00423028(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  if ((param_2 != '\0') && (cVar1 = FUN_00423481(), cVar1 != '\0')) {
    FUN_0042349d();
  }
  iVar3 = *(int *)(param_1 + 400);
  if (iVar3 != 0) goto LAB_00423062;
  while (iVar3 = param_1, iVar3 != 0) {
LAB_00423062:
    FUN_00422d79(0xc,0,0);
    local_8 = 0;
    iVar4 = (*(int *)(iVar3 + 0x134) - *(int *)(iVar3 + 0x130)) / 0x24 + -1;
    if (0 < iVar4) {
      _param_2 = 0x24;
      do {
        if ((_param_2 < 0x24) ||
           ((*(int *)(iVar3 + 0x134) - *(int *)(iVar3 + 0x130)) / 0x24 + -1 <= local_8)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar3 + 0x130) + _param_2;
        }
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_00407498((int)*(short *)(iVar2 + 0x10));
        }
        if (iVar2 != 0) {
          if ((_param_2 < 0x24) ||
             ((*(int *)(iVar3 + 0x134) - *(int *)(iVar3 + 0x130)) / 0x24 + -1 <= local_8)) {
            iVar2 = 0;
          }
          else {
            iVar2 = *(int *)(iVar3 + 0x130) + _param_2;
          }
          if (iVar2 != 0) {
            FUN_00407498((int)*(short *)(iVar2 + 0x10));
          }
          FUN_00422d79(0xc,0,0);
        }
        local_8 = local_8 + 1;
        _param_2 = _param_2 + 0x24;
      } while (local_8 < iVar4);
    }
    param_1 = *(int *)(iVar3 + 0x18c);
  }
  FUN_004357f6(0);
  return;
}

