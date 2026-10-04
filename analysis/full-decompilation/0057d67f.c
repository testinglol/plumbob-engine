
undefined4 __fastcall FUN_0057d67f(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x94) == *(int *)(param_1 + 0x98)) {
    local_8 = 0;
    FUN_00580ad6(0x100,&local_8);
    piVar1 = (int *)(param_1 + 0xa0);
    iVar3 = 0;
    do {
      *piVar1 = *piVar1 + 1;
      *(int *)(iVar3 + *(int *)(param_1 + 0x94)) = *piVar1;
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x400);
  }
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x98) + -4);
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -4;
  return uVar2;
}

