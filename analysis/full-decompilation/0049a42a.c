
void FUN_0049a42a(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  byte local_7;
  byte local_6;
  byte local_5;
  
  if (*(int *)(DAT_006e486c + 0x34) == 1) {
    DAT_006ede5c = FUN_0049a7e6;
    DAT_006ede60 = FUN_0049abbf;
  }
  else {
    DAT_006ede5c = FUN_0049a58d;
    DAT_006ede60 = FUN_0049a9ff;
  }
  FUN_004bbabe(1);
  FUN_004b9c72();
  if (DAT_006ede64 == '\0') {
    local_7 = 0;
    local_1c = 0;
    DAT_006ede64 = '\x01';
    do {
      local_6 = 0;
      local_18 = 0;
      do {
        local_5 = 0;
        iVar3 = 0;
        do {
          local_14 = 0;
          do {
            local_10 = 0;
            do {
              iVar2 = 0;
              do {
                __ftol();
                iVar2 = iVar2 + 1;
              } while (iVar2 < 8);
              local_10 = local_10 + 1;
            } while (local_10 < 8);
            local_14 = local_14 + 1;
          } while (local_14 < 8);
          iVar2 = __ftol();
          iVar1 = local_18 + iVar3;
          iVar3 = iVar3 + 0x20;
          local_5 = local_5 + 1;
          (&DAT_006e5e5c)[local_1c + iVar1 * 0x20] = (char)(iVar2 >> 3);
        } while (local_5 < 0x20);
        local_6 = local_6 + 1;
        local_18 = local_18 + 1;
      } while (local_6 < 0x20);
      local_7 = local_7 + 1;
      local_1c = local_1c + 1;
    } while (local_7 < 0x20);
  }
  return;
}

