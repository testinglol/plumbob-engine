
undefined4 __thiscall FUN_00524a97(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_005d0a09();
  if (((iVar1 == param_1) || (param_2 == 0xd)) || (param_2 == 0x1b)) {
    for (puVar2 = *(undefined4 **)(param_1 + 0xd8); puVar2 != *(undefined4 **)(param_1 + 0xdc);
        puVar2 = puVar2 + 3) {
      if ((puVar2[1] != 0) && (puVar2[1] == param_2)) {
        if (puVar2 != *(undefined4 **)(param_1 + 0xdc)) {
          uVar3 = FUN_00524a57(*puVar2);
          return uVar3;
        }
        break;
      }
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

