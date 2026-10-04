
void __fastcall FUN_004a17aa(int *param_1)

{
  if (param_1[1] != 0) {
    FUN_004a18ec(*(undefined4 *)(*param_1 + 4));
    *(int *)(*param_1 + 8) = *param_1;
    *(undefined4 *)(*param_1 + 4) = 0;
    *(int *)(*param_1 + 0xc) = *param_1;
    param_1[1] = 0;
  }
  return;
}

