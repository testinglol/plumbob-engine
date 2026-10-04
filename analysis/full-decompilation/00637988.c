
undefined1 * FUN_00637988(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  bVar1 = true;
  if (DAT_006daa84 == (undefined1 *)0x0) {
    DAT_006daa84 = _malloc(0x351);
  }
  *DAT_006daa84 = 0;
  FUN_00637b59(DAT_006daa84,3,PTR_s_LC_COLLATE_006daa8c,&DAT_006c42ec,PTR_DAT_006daa90);
  ppuVar3 = &PTR_DAT_006daa90;
  do {
    FUN_006358c0(DAT_006daa84,&DAT_006c145c);
    ppuVar4 = ppuVar3 + 3;
    iVar2 = _strcmp(*ppuVar3,ppuVar3[3]);
    if (iVar2 != 0) {
      bVar1 = false;
    }
    FUN_00637b59(DAT_006daa84,3,ppuVar3[2],&DAT_006c42ec,*ppuVar4);
    ppuVar3 = ppuVar4;
  } while ((int)ppuVar4 < 0x6daac0);
  if (!bVar1) {
    return DAT_006daa84;
  }
  FUN_00634ecc(DAT_006daa84);
  DAT_006daa84 = (undefined1 *)0x0;
  return PTR_DAT_006daa9c;
}

