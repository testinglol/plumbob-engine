
void FUN_004ea674(int param_1,undefined4 param_2,char param_3,char param_4)

{
  char cVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar3;
  
  if (DAT_006f2630 == 0) {
    return;
  }
  cVar1 = FUN_005a5e72();
  if (cVar1 == '\0') {
    return;
  }
  if (param_1 < 0) {
    return;
  }
  if ((DAT_006f264c - DAT_006f2648) / 0x44 <= param_1) {
    return;
  }
  FUN_004e8a7a();
  FUN_004096c2();
  iVar2 = FUN_004e9744(param_1);
  if (iVar2 == 0) {
LAB_004ea70b:
    if ((char)param_2 != '\0') {
      FUN_00458278(1);
      FUN_004e8d99(param_1,0x1f,1);
      uVar3 = extraout_var_00;
      goto LAB_004ea736;
    }
  }
  else if ((char)param_2 != '\0') {
    FUN_00425ab3(iVar2);
    if (param_4 != '\0') {
      FUN_00425316(*(undefined4 *)(DAT_006e486c + 0x44));
    }
    goto LAB_004ea70b;
  }
  FUN_004e9a99(param_1,&DAT_006f2638);
  uVar3 = extraout_var;
LAB_004ea736:
  if ((iVar2 != 0) && (param_3 != '\0')) {
    FUN_0044127f(CONCAT22(uVar3,*(undefined2 *)(iVar2 + 0xf0)));
  }
  FUN_004094f4(param_2);
  FUN_004cee86(0x20000000);
  iVar2 = DAT_006f2630;
  if (DAT_006f2630 != 0) {
    FUN_00408c4f();
    FUN_006321f0(iVar2);
  }
  DAT_006f2630 = 0;
  return;
}

