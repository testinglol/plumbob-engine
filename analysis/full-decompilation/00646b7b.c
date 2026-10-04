
uint FUN_00646b7b(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00646bc6();
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_00646c58(uVar1);
  return uVar1;
}

