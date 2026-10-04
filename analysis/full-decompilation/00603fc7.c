
char __thiscall FUN_00603fc7(int param_1,undefined4 param_2)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    cVar1 = '\x01';
  }
  else {
    cVar1 = FUN_00607aba(param_2);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x74) = param_2;
    }
  }
  return cVar1;
}

