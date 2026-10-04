
undefined4 __fastcall FUN_0057bf27(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 0x8c))();
  *(int *)(param_1 + 0x20) = iVar2;
  if (iVar2 == 0) {
    uVar3 = (**(code **)(*piVar1 + 0x78))();
    *(undefined4 *)(param_1 + 0x20) = uVar3;
  }
  (**(code **)(**(int **)(param_1 + 0x20) + 0x3c))(0);
  (**(code **)(**(int **)(param_1 + 0x20) + 0x14))(0,0,0);
  return 1;
}

