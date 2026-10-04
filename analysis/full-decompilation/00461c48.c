
void __fastcall FUN_00461c48(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_12;
  undefined1 local_f;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  local_a = 0;
  local_8 = 0;
  local_c = (undefined1)*(undefined4 *)(param_1 + 0xc);
  local_7 = 0;
  local_6 = 0;
  local_12 = 0;
  local_f = 0;
  local_b = local_c;
  FUN_00461b74(&local_8);
  FUN_00461b74(&local_c);
  local_1c = 0;
  local_16 = 0;
  FUN_004619d2(local_24);
  puVar2 = (undefined4 *)FUN_004619b0(local_2c);
  local_1c = *puVar2;
  FUN_00461b74(puVar2 + 1);
  while( true ) {
    iVar3 = FUN_004619d2(local_2c);
    cVar1 = FUN_0046198c(iVar3 + 4);
    if (cVar1 != '\0') break;
    pcVar4 = (char *)FUN_00461941(&local_c);
    if (*(char *)(*(int *)(*(int *)(param_1 + 0x10) + *pcVar4 * 4) + (int)pcVar4[1]) == '\x10') {
      pcVar4 = (char *)FUN_00461941(&local_8);
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x10) + *pcVar4 * 4) + (int)pcVar4[1]) = 0xff;
    }
    FUN_00461961();
  }
  return;
}

