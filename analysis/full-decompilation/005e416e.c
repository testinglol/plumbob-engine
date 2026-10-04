
undefined4 __thiscall FUN_005e416e(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x178);
  if (iVar2 == 0) {
    piVar1 = (int *)FUN_005e7743();
    iVar2 = (**(code **)(*piVar1 + 0x50))(*(undefined4 *)(param_1 + 0xf0));
  }
  return *(undefined4 *)(iVar2 + param_2 * 4);
}

