
void __fastcall FUN_00597c25(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x58) != 0) &&
     (iVar2 = (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8)) / 0xc, 0 < iVar2)) {
    iVar3 = 0;
    do {
      piVar1 = (int *)(iVar3 + *(int *)(param_1 + 8));
      iVar3 = iVar3 + 0xc;
      iVar2 = iVar2 + -1;
      *(undefined4 *)(*piVar1 + 0x68) = *(undefined4 *)(param_1 + 0x14);
    } while (iVar2 != 0);
  }
  return;
}

