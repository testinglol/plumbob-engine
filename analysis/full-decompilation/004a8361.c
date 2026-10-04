
void __thiscall FUN_004a8361(int *param_1,char param_2)

{
  if ((char)param_1[0x12] != param_2) {
    *(char *)(param_1 + 0x12) = param_2;
    if (*(char *)((int)param_1 + 0x49) != '\0') {
      FUN_004ac287();
      *(undefined1 *)((int)param_1 + 0x49) = 0;
    }
    *(undefined1 *)((int)param_1 + 0x4e) = 1;
    (**(code **)(*param_1 + 0x48))();
  }
  return;
}

