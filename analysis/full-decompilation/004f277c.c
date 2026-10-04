
undefined4 __fastcall FUN_004f277c(int param_1)

{
  short sVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined **local_118 [3];
  undefined1 local_10c [260];
  int local_8;
  
  if (DAT_006f2a04 == '\0') {
    local_8 = param_1;
    FUN_004d3125();
    *(undefined2 *)(DAT_006e486c[9] + 0x12e) = 1;
    cVar2 = FUN_004074f7();
    if (((((cVar2 == '\0') || (*(short *)(DAT_006e486c[7] + 0x50) != 0)) &&
         ((cVar2 = FUN_0040750e(), cVar2 == '\0' || (*(short *)(DAT_006e486c[7] + 0x50) != 0)))) &&
        (((cVar2 = FUN_0042886f(), cVar2 == '\0' || (*(short *)(DAT_006e486c[7] + 0x50) != 0)) &&
         ((cVar2 = FUN_004074d9(), cVar2 == '\0' || (*(short *)(DAT_006e486c[7] + 0x50) != 0))))))
       && (((cVar2 = FUN_00407525(), cVar2 == '\0' ||
            (*(int *)(*(int *)(*DAT_006e486c + 0x10) + 0x10c) != 0)) ||
           (*(short *)(DAT_006e486c[7] + 0x50) != 0)))) {
      iVar4 = FUN_004286d1();
      if (iVar4 != 0) {
        FUN_004f6994(DAT_006f2850,DAT_006f2840,0,0);
        return 0;
      }
      iVar4 = *(int *)(*DAT_006e486c + 0x10);
      if (((iVar4 != 0) && (*(int *)(iVar4 + 0x10c) != 0)) &&
         (cVar2 = FUN_004074bc(), cVar2 != '\0')) {
        FUN_0046f824(local_10c,0,0x104);
        local_118[0] = &PTR_FUN_006664e8;
        uVar3 = FUN_0041532c(0x57,0,local_118);
        FUN_004eea6b(uVar3);
        FUN_004288ff(local_118,iVar4);
        FUN_004e609e();
        cVar2 = FUN_004e6445();
        if (cVar2 != '\0') {
          FUN_004e2fc2(*(undefined4 *)(iVar4 + 0x10c));
        }
      }
      if (*(short *)(DAT_006e486c[7] + 0x50) == 1) {
        FUN_004fc804();
      }
      *(undefined1 *)(param_1 + 0xf7) = 0;
    }
    else {
      uVar3 = FUN_004e99a9();
      iVar4 = FUN_004e9744(uVar3);
      sVar1 = *(short *)(iVar4 + 0x606);
      uVar3 = FUN_0046d9e5();
      iVar4 = FUN_00425db3((int)sVar1);
      *(undefined4 *)(iVar4 + 0x118) = uVar3;
      FUN_00425b05();
      FUN_00425316(DAT_006e486c[0x11]);
    }
    uVar3 = FUN_005e749a(0);
    FUN_005dadbc(uVar3,1);
    FUN_005ddddb();
    FUN_004cee86(0xffffffff);
  }
  return 1;
}

