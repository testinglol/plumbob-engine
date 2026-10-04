
int __fastcall FUN_005c9821(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x98) != 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0xec) + 0x7c))
                      (*(int **)(param_1 + 0xec),*(int *)(param_1 + 0x98));
    *(int *)(param_1 + 4) = iVar2;
    if (iVar2 != 0) {
      if (iVar2 != -0x7789fe3e) {
        return iVar2;
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 0xec) + 0x6c))(*(int **)(param_1 + 0xec));
      *(int *)(param_1 + 4) = iVar2;
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 0xec) + 0x7c))
                        (*(int **)(param_1 + 0xec),*(undefined4 *)(param_1 + 0x98));
      *(int *)(param_1 + 4) = iVar2;
      if (iVar2 != 0) {
        return iVar2;
      }
      piVar1 = *(int **)(param_1 + 0xf8);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x7c))(piVar1,*(undefined4 *)(param_1 + 0x98));
        *(int *)(param_1 + 4) = iVar2;
        if (iVar2 != 0) {
          return iVar2;
        }
      }
    }
  }
  return *(int *)(param_1 + 4);
}

