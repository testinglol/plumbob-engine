
void FUN_004ff6af(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  iVar2 = 0;
  piVar3 = &DAT_006f2a74;
  do {
    if ((*piVar3 != 0) && ((&DAT_006f2a28)[iVar2] != '\0')) {
      (**(code **)(*piVar1 + 0x14))(*piVar3);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar3 < 0x6f2ad0);
  (**(code **)(*piVar1 + 0x14))(DAT_006f2ad0);
  return;
}

