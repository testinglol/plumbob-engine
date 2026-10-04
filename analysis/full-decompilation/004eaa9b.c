
void FUN_004eaa9b(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  cVar1 = FUN_004eab60(param_1);
  if (cVar1 != '\0') {
    FUN_0040cc8c(param_2,1);
    iVar2 = FUN_004e9744(param_1);
    if (iVar2 != 0) {
      FUN_0044127f(*(undefined2 *)(iVar2 + 0xf0));
    }
    FUN_004e978e(param_1);
    piVar3 = (int *)FUN_004e9744(param_1);
    if (piVar3 != (int *)0x0) {
      FUN_0046f824(local_44,0,0x40);
      local_50[0] = &PTR_FUN_0066651c;
      FUN_0046f847(s_design_a_person_006c9e20,0xffffffff);
      uVar4 = FUN_00402246(local_50);
      if ((short)uVar4 == 0) {
        FUN_0044582f((int)(short)piVar3[0x3c],1,0);
      }
      else {
        (**(code **)(*piVar3 + 0x34))(piVar3,0,uVar4,0);
      }
    }
  }
  return;
}

