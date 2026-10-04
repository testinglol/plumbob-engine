
void __thiscall FUN_00510747(int param_1,char *param_2)

{
  size_t sVar1;
  
  *(char **)(param_1 + 4) = param_2;
  if (param_2 == (char *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    sVar1 = _strlen(param_2);
    *(size_t *)(param_1 + 8) = sVar1;
  }
  if (*(int *)(param_1 + 0x7c) != 0) {
    FUN_0050fcbb();
  }
  return;
}

