
void FUN_004a3bab(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    (&DAT_006efc6c)[iVar2] = 1;
    iVar3 = 0;
    do {
      iVar1 = FUN_004a3b2c(iVar3);
      if (((iVar1 == 2) || (iVar1 == 4)) || (iVar1 == 6)) {
        (&DAT_006efc6c)[iVar2] = 0;
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    iVar2 = iVar2 + 1;
    if (0xff < iVar2) {
      FUN_00636510(&DAT_006efd6c,&DAT_006f4c20,0x300);
      DAT_006efd7c = 0x10;
      DAT_006efe7c = 0x10;
      DAT_006eff7c = 0x10;
      return;
    }
  } while( true );
}

