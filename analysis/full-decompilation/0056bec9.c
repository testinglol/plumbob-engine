
void __fastcall FUN_0056bec9(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0x104) != *(int *)(param_1 + 0x1d0)) {
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
    *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x1d0);
    if (5 < *(int *)(param_1 + 0x108)) {
      *(undefined4 *)(param_1 + 0x108) = 0;
    }
  }
  piVar4 = (int *)(param_1 + 0x154);
  iVar3 = 9;
  do {
    iVar1 = *piVar4;
    if ((*(uint *)(param_1 + 0x100) != 0) &&
       ((*(uint *)(iVar1 + 0x1b4) & *(uint *)(param_1 + 0x100)) != 0)) {
      if ((*(int *)(iVar1 + 0x1d8) == 0x2a) || (*(int *)(iVar1 + 0x1d8) == 0x28)) {
        iVar2 = *(int *)(iVar1 + 0x20c) + -10;
      }
      else {
        iVar2 = *(int *)(iVar1 + 0x20c) + -0x46;
      }
      FUN_0056bf55(*(int *)(iVar1 + 0x208) + -0x18,iVar2);
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

