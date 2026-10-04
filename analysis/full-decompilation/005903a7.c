
void __fastcall FUN_005903a7(int *param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (param_1[0x6a] != 6) {
    iVar4 = -1;
    if (param_1[0x69] == 0) {
      cVar2 = FUN_00589fd2();
      uVar1 = (uint)(cVar2 != '\0');
      param_1[0x6a] = uVar1;
      if ((uVar1 != 0) && (uVar1 < 6)) {
        iVar4 = 0;
      }
    }
    if (iVar4 != param_1[0x6b]) {
      (**(code **)(*param_1 + 0x104))(param_1 + 0x4f);
      if (iVar4 == 0) {
        iVar3 = (**(code **)(*param_1 + 0xf4))(0x26);
        if (iVar3 != 0) {
          iVar3 = (**(code **)(*param_1 + 0x100))(param_1 + 0x4f,iVar3,0);
          if (iVar3 != 0) {
            FUN_00598687(10);
          }
        }
      }
      param_1[0x6b] = iVar4;
    }
  }
  return;
}

