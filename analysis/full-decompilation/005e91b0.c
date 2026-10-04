
undefined4 __thiscall
FUN_005e91b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  cVar2 = (**(code **)(*param_1 + 0x8c))(0x20);
  if ((cVar2 == '\0') || (cVar2 = (**(code **)(*param_1 + 0x8c))(4), cVar2 == '\0')) {
    puVar4 = &param_3;
    puVar5 = &param_2;
    uVar3 = (**(code **)(*param_1 + 0x18))(puVar5,puVar4);
    FUN_004d26ba(uVar3,puVar5,puVar4);
    uVar1 = param_3;
    uVar3 = param_2;
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    if ((puVar4 == (undefined4 *)0x0) || (cVar2 = FUN_005da398(puVar4), cVar2 == '\0')) {
      uVar3 = 0;
    }
    else {
      local_8 = param_4;
      local_14 = 0xd;
      local_10 = uVar3;
      local_c = uVar1;
      uVar3 = (**(code **)*puVar4)(&local_14);
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

