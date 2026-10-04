
int __cdecl FUN_60019fce(int *param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = FUN_60019f9c(*param_1);
  local_c = 0;
  for (local_10 = 0; local_10 < iVar1; local_10 = local_10 + 1) {
    if (*(char *)(param_1[1] + local_10) != '\0') {
      local_c = local_c + 1;
    }
  }
  return local_c;
}

