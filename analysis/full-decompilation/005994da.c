
void __thiscall FUN_005994da(int param_1,char param_2)

{
  if (((param_2 != '\0') || (*(int *)(param_1 + 0xa0) != *(int *)(param_1 + 0xa4))) &&
     (*(int *)(param_1 + 0x60) != 0)) {
    FUN_00596177(&DAT_006f75d0,&DAT_006f75c0);
    *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 1;
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
    FUN_00599604();
  }
  return;
}

