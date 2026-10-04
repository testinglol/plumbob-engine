
void FUN_00427cfb(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_20;
  int local_1c [6];
  
  FUN_0040727f();
  local_1c[4] = 0;
  local_1c[0] = 0x865a6812;
  local_20 = 0x81e6bef9;
  local_1c[1] = 0xef121974;
  local_1c[5] = *(undefined4 *)(*DAT_006e486c + 0x14);
  local_1c[2] = 0xa4258067;
  local_1c[3] = 0xaed879c5;
  iVar3 = -0x7e194107;
  puVar2 = &local_20;
  while ((iVar1 = FUN_00440914(iVar3), iVar1 != 0 || (iVar3 = FUN_0043acf5(iVar3), iVar3 == 0))) {
    iVar3 = puVar2[1];
    puVar2 = puVar2 + 1;
    if (iVar3 == 0) {
      return;
    }
  }
  FUN_0046f8cb(s_Lot_doesn_t_have_an_instance_of_006c26e0);
  FUN_0046f847(*(undefined4 *)(iVar3 + 0x18),0xffffffff);
  FUN_0046f847(&DAT_006c26dc,0xffffffff);
  return;
}

