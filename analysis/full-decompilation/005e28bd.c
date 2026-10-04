
undefined1 __fastcall FUN_005e28bd(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0xe4))();
  if (cVar1 == '\0') {
    return 0;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  return 1;
}

