
void __fastcall FUN_004b050c(int param_1)

{
  if (((*(char *)(param_1 + 0x179) != '\x01') && (*(char *)(param_1 + 0x178) != '\0')) &&
     (DAT_006e4870 == '\0')) {
    DAT_006e4870 = '\x01';
    *(undefined4 *)(param_1 + 0x1b8) = DAT_006fe838;
    DAT_006fe838 = 0;
  }
  return;
}

