
void FUN_0043fd68(int param_1,int *param_2)

{
  int iVar1;
  short local_8 [2];
  
  if (*(int *)(param_1 + 0xc) != 0) {
    if (*param_2 == 0) {
      local_8[0] = 0;
    }
    else {
      local_8[0] = *(short *)(*param_2 + 0xf0);
    }
  }
  FUN_00464973(local_8,1);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = FUN_00407498((int)local_8[0]);
    *param_2 = iVar1;
  }
  return;
}

