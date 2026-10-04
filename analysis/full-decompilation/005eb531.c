
void __thiscall FUN_005eb531(int *param_1,undefined4 param_2)

{
  if ((char)param_1[99] == '\0') {
    (**(code **)(*param_1 + 0x25c))();
  }
  else {
    FUN_005dac30(0x10,param_1,param_2);
    *(undefined1 *)(param_1 + 0x53) = 0;
    *(undefined1 *)((int)param_1 + 0x14d) = 0;
  }
  return;
}

