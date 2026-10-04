
void __thiscall FUN_0056e8c4(byte *param_1,int param_2)

{
  if (param_2 == 0) {
    if ((*param_1 & 4) != 0) {
      *param_1 = *param_1 & 0xfe;
      return;
    }
  }
  else if (param_2 == 1) {
    *param_1 = *param_1 | 2;
    return;
  }
  *param_1 = *param_1 & 0xfd;
  return;
}

