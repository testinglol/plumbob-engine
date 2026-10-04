
int FUN_0041d3d0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) != -1) && (iVar1 = FUN_0041d3ff(*(int *)(param_1 + 0xc)), iVar1 != 0)
     ) {
    return iVar1;
  }
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00420028(*(int *)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return 0;
}

