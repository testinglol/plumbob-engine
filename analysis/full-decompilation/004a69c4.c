
undefined4 FUN_004a69c4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(DAT_006e486c + 4);
  iVar2 = (**(code **)(*piVar1 + 0x14))();
  iVar3 = (**(code **)(*piVar1 + 0x24))();
  return *(undefined4 *)(iVar3 + (0x1e - iVar2) * 4);
}

