
int FUN_004efa01(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x144))();
  iVar2 = (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
  if (*(char *)(iVar2 + 0x75) == '\0') {
    iVar2 = (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
    if (*(char *)(iVar2 + 0x90) == '\0') {
      piVar1 = (int *)(**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
      iVar2 = (**(code **)(*piVar1 + 0x138))();
      return *(int *)(iVar2 + 4);
    }
  }
  iVar2 = (**(code **)(*piVar1 + 0x50))();
  if (iVar2 == 0) {
    iVar2 = piVar1[1];
  }
  return iVar2;
}

