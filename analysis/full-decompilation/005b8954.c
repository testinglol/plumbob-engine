
void __fastcall FUN_005b8954(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  if (iVar1 != iVar2) {
    iVar4 = 0;
    uVar3 = 0;
    if (iVar1 != iVar2) {
      do {
        if (*(char *)(iVar2 + uVar3) != ' ') break;
        iVar4 = iVar4 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(iVar1 - iVar2));
      if (iVar4 != 0) {
        FUN_00406466(0,iVar4);
      }
    }
  }
  return;
}

