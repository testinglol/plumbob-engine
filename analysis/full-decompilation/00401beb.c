
undefined4 * FUN_00401beb(uint param_1,uint *param_2)

{
  size_t _Size;
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = *param_2;
  do {
    puVar2 = DAT_006de5b4;
    uVar3 = uVar3 * param_1;
    uVar1 = DAT_006de5b8 - (int)DAT_006de5b4;
    if (uVar3 <= uVar1) {
      DAT_006de5b4 = (undefined4 *)((int)DAT_006de5b4 + uVar3);
      return puVar2;
    }
    if (param_1 <= uVar1) {
      *param_2 = uVar1 / param_1;
      puVar2 = DAT_006de5b4;
      DAT_006de5b4 = (undefined4 *)((int)DAT_006de5b4 + (uVar1 / param_1) * param_1);
      return puVar2;
    }
    _Size = ((DAT_006de5b0 >> 4) + 7 & 0xfffffff8) + uVar3 * 2;
    if (uVar1 != 0) {
      *DAT_006de5b4 = *(undefined4 *)(&DAT_006de560 + (uVar1 + 7 >> 3) * 4);
      *(undefined4 **)(&DAT_006de560 + (uVar1 + 7 >> 3) * 4) = DAT_006de5b4;
    }
    puVar2 = _malloc(_Size);
    uVar3 = param_1;
    if (puVar2 == (undefined4 *)0x0) {
      for (; uVar3 < 0x81; uVar3 = uVar3 + 8) {
        DAT_006de5b4 = *(undefined4 **)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4);
        if (DAT_006de5b4 != (undefined4 *)0x0) {
          *(undefined4 *)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4) = *DAT_006de5b4;
          DAT_006de5b8 = (int)DAT_006de5b4 + uVar3;
          goto LAB_00401cac;
        }
      }
      DAT_006de5b8 = 0;
      DAT_006de5b4 = puVar2;
      puVar2 = _malloc(_Size);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)FUN_00401b39(_Size);
      }
    }
    DAT_006de5b0 = DAT_006de5b0 + _Size;
    DAT_006de5b8 = (int)puVar2 + _Size;
    DAT_006de5b4 = puVar2;
LAB_00401cac:
    uVar3 = *param_2;
  } while( true );
}

