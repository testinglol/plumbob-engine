
int FUN_0060af52(char *param_1,size_t param_2)

{
  int local_18 [5];
  
  if (param_2 == 0xffffffff) {
    param_2 = _strlen(param_1);
  }
  FUN_0060980f(local_18,param_1,param_2);
  if (local_18[0] == 0) {
    local_18[0] = 1;
  }
  return local_18[0];
}

