
void FUN_00615300(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00615330(param_1);
  if ((iVar1 == 0) && (DAT_006ff840 < 0xff)) {
    *(undefined4 *)(&DAT_006ff444 + DAT_006ff840 * 4) = *param_1;
    DAT_006ff840 = DAT_006ff840 + 1;
  }
  return;
}

