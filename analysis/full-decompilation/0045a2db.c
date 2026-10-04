
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0045a2db(int param_1,undefined4 param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  short sVar3;
  short sVar4;
  uint local_10;
  float local_c;
  float local_8;
  
  puVar2 = param_3;
  if ((param_3[3] & 1) == 0) {
    bVar1 = param_3[2];
    if ((bVar1 < 5) || ((9 < bVar1 && ((bVar1 < 0xe || (0xf < bVar1)))))) {
      param_3 = (undefined1 *)0x1a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_3,&DAT_00698f30);
    }
    sVar3 = FUN_00453181(*param_3,*(undefined2 *)(param_3 + 4),0);
    sVar4 = FUN_00453181(puVar2[1],*(undefined2 *)(puVar2 + 6),0);
    local_10 = (uint)(byte)puVar2[2];
    param_3 = (undefined1 *)(int)sVar4;
    local_c = (float)(int)sVar3 * _DAT_00667408;
    local_8 = (float)(int)param_3;
    FUN_0045f995(&local_10);
  }
  else {
    FUN_004609a6(*(undefined4 *)(param_1 + 0xad0),*(undefined4 *)(param_1 + 0xad4));
  }
  return 1;
}

