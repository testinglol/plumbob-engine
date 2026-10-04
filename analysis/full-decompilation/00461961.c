
void __fastcall FUN_00461961(undefined4 *param_1)

{
  undefined1 uVar1;
  
  *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
  if (*(char *)(param_1 + 1) == ((undefined1 *)*param_1)[3]) {
    uVar1 = *(undefined1 *)*param_1;
    *(char *)((int)param_1 + 5) = *(char *)((int)param_1 + 5) + '\x01';
    *(undefined1 *)(param_1 + 1) = uVar1;
  }
  return;
}

