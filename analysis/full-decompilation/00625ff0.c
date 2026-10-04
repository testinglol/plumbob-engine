
undefined4 * FUN_00625ff0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  piVar1 = param_1;
  puVar2 = (undefined4 *)
           FUN_00625580(*(undefined4 *)(*param_1 + 0x10),*(undefined4 *)(*param_1 + 0x14),0x20);
  FUN_006219b0(&param_1,1,piVar1,0,0);
  uVar3 = FUN_00624680(param_1,0);
  FUN_00610450(param_1,uVar3,puVar2[1],puVar2[2]);
  FUN_00626170(param_1);
  FUN_005a9340(*puVar2);
  *puVar2 = uVar3;
  return puVar2;
}

