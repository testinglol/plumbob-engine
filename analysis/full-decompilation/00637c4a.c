
void FUN_00637c4a(undefined4 param_1,int param_2)

{
  FUN_006358b0(param_1,param_2);
  if (*(char *)(param_2 + 0x40) != '\0') {
    FUN_00637b59(param_1,2,&DAT_006c111c,param_2 + 0x40);
  }
  if (*(char *)(param_2 + 0x80) != '\0') {
    FUN_00637b59(param_1,2,&DAT_006c26dc,param_2 + 0x80);
  }
  return;
}

