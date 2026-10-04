
void __thiscall FUN_004cefe5(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x800040;
  *(char *)(param_1 + 0x40) = (char)param_2;
  if (*(int *)(param_1 + 8) == 2) {
    FUN_004d3356(param_2,0);
    if ((char)param_2 != '\0') {
      FUN_004b1de9();
    }
  }
  return;
}

