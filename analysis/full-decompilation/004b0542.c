
void __fastcall FUN_004b0542(int *param_1)

{
  if ((*(char *)((int)param_1 + 0x179) == '\0') && (DAT_006e4870 == '\x01')) {
    DAT_006e4870 = '\0';
    FUN_004c9cb5();
    DAT_006fe838 = param_1[0x6e];
    *(undefined1 *)((int)param_1 + 0x17a) = 0;
    (**(code **)(*param_1 + 0x48))();
    (**(code **)(*DAT_006fe8bc + 0x18))();
    FUN_005db0b7();
  }
  return;
}

