
void __fastcall FUN_005424ee(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  iVar4 = 0x15;
  puVar3 = (undefined4 *)(param_1 + 0x9c);
  do {
    iVar1 = _rand();
    puVar3[-1] = iVar1 % 3;
    *puVar3 = 1;
    puVar3[1] = 0xffffff92;
    iVar1 = _rand();
    iVar4 = iVar4 + -1;
    puVar3[2] = iVar1 % 2 + 2;
    puVar3[-2] = 0;
    puVar3[-3] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3 = puVar3 + 9;
  } while (iVar4 != 0);
  local_8 = 0;
  iVar1 = 0x1ce;
  iVar4 = 0x3c;
  puVar3 = (undefined4 *)(param_1 + 0xac);
  do {
    puVar3[-6] = iVar4;
    *puVar3 = 0;
    iVar2 = _rand();
    iVar4 = iVar4 + 0x10;
    iVar2 = (iVar2 % 5 + -0x20) * local_8;
    local_8 = local_8 + 1;
    puVar3[-7] = iVar2 + 0x156;
    puVar3[-1] = iVar1;
    puVar3[1] = 2;
    iVar1 = iVar1 + -0x20;
    puVar3 = puVar3 + 9;
  } while (0xce < iVar1);
  local_c = 0;
  local_8 = 10;
  iVar4 = 0x3c;
  iVar1 = 0x1ce;
  puVar3 = (undefined4 *)(param_1 + 0x214);
  do {
    puVar3[-6] = iVar4;
    *puVar3 = 0;
    iVar2 = _rand();
    iVar4 = iVar4 + 0x10;
    iVar2 = (iVar2 % 5) * local_8 - local_c;
    local_c = local_c + 0x30;
    local_8 = local_8 + 1;
    puVar3[-7] = iVar2 + 0x11a;
    puVar3[-1] = iVar1;
    puVar3[1] = 3;
    iVar1 = iVar1 + -0x30;
    puVar3 = puVar3 + 9;
  } while (0xae < iVar1);
  iVar4 = 0x3c;
  puVar3 = (undefined4 *)(param_1 + 0x310);
  iVar1 = 0;
  do {
    puVar3[-6] = iVar4;
    *puVar3 = 0;
    iVar2 = _rand();
    puVar3[-7] = (iVar2 % 5) * iVar1 + 0x8e;
    iVar2 = _rand();
    iVar4 = iVar4 + 10;
    puVar3[-1] = (iVar2 % 5) * iVar1 + 0x106;
    puVar3[1] = 2;
    iVar2 = iVar1 + 0x12;
    puVar3 = puVar3 + 9;
    iVar1 = iVar1 + 1;
  } while (iVar2 < 0x15);
  return;
}

