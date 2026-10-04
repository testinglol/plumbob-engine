
void __fastcall FUN_005ea089(int *param_1)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint *unaff_retaddr;
  uint *puVar5;
  uint *puVar6;
  
  cVar2 = (**(code **)(param_1[0x35] + 8))(1);
  if (cVar2 == '\0') {
    FUN_005dc8b5(unaff_retaddr);
  }
  else {
    uVar1 = *unaff_retaddr;
    if ((6 < uVar1) && ((uVar1 < 9 || ((10 < uVar1 && (uVar1 < 0xe)))))) {
      puVar6 = unaff_retaddr + 2;
      puVar5 = unaff_retaddr + 1;
      uVar3 = (**(code **)(*param_1 + 0x18))(puVar5,puVar6);
      FUN_004d26ba(uVar3,puVar5,puVar6);
    }
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    (**(code **)*puVar4)(unaff_retaddr);
  }
  return;
}

