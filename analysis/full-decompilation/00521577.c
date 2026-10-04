
void __thiscall FUN_00521577(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x1e8) = *param_2;
  *(undefined4 *)(param_1 + 0x1ec) = param_2[1];
  iVar3 = param_2[2];
  *(int *)(param_1 + 0x1f0) = iVar3;
  *(undefined4 *)(param_1 + 500) = param_2[3];
  *(int *)(param_1 + 0x1f8) = (iVar3 - *(int *)(param_1 + 0x1e8)) + 3;
  piVar1 = (int *)FUN_005e40a5();
  iVar3 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x20);
  iVar2 = (**(code **)(*piVar1 + 0x70))();
  if (iVar2 < iVar3) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x20);
    piVar1 = (int *)FUN_005e40a5();
    iVar2 = (**(code **)(*piVar1 + 0x70))();
    iVar3 = (iVar3 - iVar2) / 2;
    *(int *)(param_1 + 0x1ec) = *(int *)(param_1 + 0x1ec) + iVar3;
    *(int *)(param_1 + 500) = *(int *)(param_1 + 500) + iVar3;
    *(undefined4 *)(param_1 + 0x1fc) = 0;
  }
  else {
    piVar1 = (int *)FUN_005e40a5();
    iVar3 = *(int *)(*(int *)(param_1 + 0x1e0) + 0x20);
    iVar2 = (**(code **)(*piVar1 + 0x70))();
    *(int *)(param_1 + 0x1fc) = (iVar2 - iVar3) / 2;
  }
  FUN_004ec186(*(int *)(*(int *)(param_1 + 0x1e0) + 0x1c) + 3 + *(int *)(param_1 + 0x1f8));
  return;
}

