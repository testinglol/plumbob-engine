
undefined1 __fastcall FUN_005faa18(int *param_1)

{
  char cVar1;
  
  if (param_1[1] == 0) {
    return 5;
  }
  cVar1 = (**(code **)(*param_1 + 0x24))();
  return cVar1 != '\0';
}

