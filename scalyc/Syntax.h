#ifndef __scalyc__Syntax__
#define __scalyc__Syntax__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {

class SyntaxNode : public Object {
public:
    Position* start;
    Position* end;
    SyntaxNode* parent;

    virtual bool _isProgram();
    virtual bool _isCompilationUnit();
    virtual bool _isStatement();
    virtual bool _isDeclaration();
    virtual bool _isConstantDeclaration();
    virtual bool _isVariableDeclaration();
    virtual bool _isMutableDeclaration();
    virtual bool _isFunctionDeclaration();
    virtual bool _isEnumDeclaration();
    virtual bool _isClassDeclaration();
    virtual bool _isConstructorDeclaration();
    virtual bool _isExpression();
    virtual bool _isCodeBlock();
    virtual bool _isSimpleExpression();
    virtual bool _isInitializer();
    virtual bool _isBindingInitializer();
    virtual bool _isPatternInitializer();
    virtual bool _isAdditionalInitializer();
    virtual bool _isModifier();
    virtual bool _isOverrideWord();
    virtual bool _isStaticWord();
    virtual bool _isFunctionSignature();
    virtual bool _isFunctionResult();
    virtual bool _isParameterClause();
    virtual bool _isParameter();
    virtual bool _isConstParameter();
    virtual bool _isVarParameter();
    virtual bool _isThrowsClause();
    virtual bool _isEnumMember();
    virtual bool _isEnumCase();
    virtual bool _isAdditionalCase();
    virtual bool _isClassBody();
    virtual bool _isClassMember();
    virtual bool _isPrefixExpression();
    virtual bool _isPostfixExpression();
    virtual bool _isBinaryOp();
    virtual bool _isBinaryOperation();
    virtual bool _isAssignment();
    virtual bool _isTypeQuery();
    virtual bool _isTypeCast();
    virtual bool _isCatchClause();
    virtual bool _isCatchPattern();
    virtual bool _isWildCardCatchPattern();
    virtual bool _isIdentifierCatchPattern();
    virtual bool _isPostfix();
    virtual bool _isOperatorPostfix();
    virtual bool _isFunctionCall();
    virtual bool _isMemberExpression();
    virtual bool _isSubscript();
    virtual bool _isExpressionElement();
    virtual bool _isPrimaryExpression();
    virtual bool _isIdentifierExpression();
    virtual bool _isLiteralExpression();
    virtual bool _isIfExpression();
    virtual bool _isSwitchExpression();
    virtual bool _isForExpression();
    virtual bool _isWhileExpression();
    virtual bool _isDoExpression();
    virtual bool _isParenthesizedExpression();
    virtual bool _isReturnExpression();
    virtual bool _isThrowExpression();
    virtual bool _isBreakExpression();
    virtual bool _isConstructorCall();
    virtual bool _isThisExpression();
    virtual bool _isNullExpression();
    virtual bool _isElseClause();
    virtual bool _isSwitchBody();
    virtual bool _isCurliedSwitchBody();
    virtual bool _isNakedSwitchBody();
    virtual bool _isSwitchCase();
    virtual bool _isCaseLabel();
    virtual bool _isItemCaseLabel();
    virtual bool _isDefaultCaseLabel();
    virtual bool _isCaseItem();
    virtual bool _isPattern();
    virtual bool _isWildcardPattern();
    virtual bool _isIdentifierPattern();
    virtual bool _isTuplePattern();
    virtual bool _isExpressionPattern();
    virtual bool _isTuplePatternElement();
    virtual bool _isCaseContent();
    virtual bool _isType();
    virtual bool _isTypeAnnotation();
    virtual bool _isSubtype();
    virtual bool _isTypePostfix();
    virtual bool _isIndexedType();
    virtual bool _isPointer();
    virtual bool _isLifeTime();
    virtual bool _isLocal();
    virtual bool _isReference();
    virtual bool _isThrown();
    virtual bool _isTypeInheritanceClause();
    virtual bool _isInheritance();
};

class Program : public SyntaxNode {
public:
    Program(string* name, string* directory, _Vector<CompilationUnit>* compilationUnits);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;
    string* directory;
    _Vector<CompilationUnit>* compilationUnits;

    virtual bool _isProgram();
};

class CompilationUnit : public SyntaxNode {
public:
    CompilationUnit(_Vector<Statement>* statements, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<Statement>* statements;
    string* fileName;

    virtual bool _isCompilationUnit();
};

class Statement : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isStatement();
    virtual bool _isDeclaration();
    virtual bool _isConstantDeclaration();
    virtual bool _isVariableDeclaration();
    virtual bool _isMutableDeclaration();
    virtual bool _isFunctionDeclaration();
    virtual bool _isEnumDeclaration();
    virtual bool _isClassDeclaration();
    virtual bool _isConstructorDeclaration();
    virtual bool _isExpression();
    virtual bool _isCodeBlock();
    virtual bool _isSimpleExpression();
};

class Declaration : public Statement {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isDeclaration();
    virtual bool _isConstantDeclaration();
    virtual bool _isVariableDeclaration();
    virtual bool _isMutableDeclaration();
    virtual bool _isFunctionDeclaration();
    virtual bool _isEnumDeclaration();
    virtual bool _isClassDeclaration();
    virtual bool _isConstructorDeclaration();
};

class Expression : public Statement {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isExpression();
    virtual bool _isCodeBlock();
    virtual bool _isSimpleExpression();
};

class ConstantDeclaration : public Declaration {
public:
    ConstantDeclaration(BindingInitializer* initializer, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    BindingInitializer* initializer;

    virtual bool _isConstantDeclaration();
};

class VariableDeclaration : public Declaration {
public:
    VariableDeclaration(BindingInitializer* initializer, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    BindingInitializer* initializer;

    virtual bool _isVariableDeclaration();
};

class MutableDeclaration : public Declaration {
public:
    MutableDeclaration(BindingInitializer* initializer, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    BindingInitializer* initializer;

    virtual bool _isMutableDeclaration();
};

class FunctionDeclaration : public Declaration {
public:
    FunctionDeclaration(_Vector<Modifier>* modifiers, string* name, FunctionSignature* signature, Expression* body, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<Modifier>* modifiers;
    string* name;
    FunctionSignature* signature;
    Expression* body;

    virtual bool _isFunctionDeclaration();
};

class EnumDeclaration : public Declaration {
public:
    EnumDeclaration(string* name, _Vector<EnumMember>* members, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;
    _Vector<EnumMember>* members;

    virtual bool _isEnumDeclaration();
};

class ClassDeclaration : public Declaration {
public:
    ClassDeclaration(string* name, TypeInheritanceClause* typeInheritanceClause, ClassBody* body, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;
    TypeInheritanceClause* typeInheritanceClause;
    ClassBody* body;

    virtual bool _isClassDeclaration();
};

class ConstructorDeclaration : public Declaration {
public:
    ConstructorDeclaration(ParameterClause* parameterClause, Expression* body, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    ParameterClause* parameterClause;
    Expression* body;

    virtual bool _isConstructorDeclaration();
};

class CodeBlock : public Expression {
public:
    CodeBlock(_Vector<Statement>* statements, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<Statement>* statements;

    virtual bool _isCodeBlock();
};

class SimpleExpression : public Expression {
public:
    SimpleExpression(PrefixExpression* prefixExpression, _Vector<BinaryOp>* binaryOps, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    PrefixExpression* prefixExpression;
    _Vector<BinaryOp>* binaryOps;

    virtual bool _isSimpleExpression();
};

class Initializer : public SyntaxNode {
public:
    Initializer(Expression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* expression;

    virtual bool _isInitializer();
};

class BindingInitializer : public SyntaxNode {
public:
    BindingInitializer(PatternInitializer* initializer, _Vector<AdditionalInitializer>* additionalInitializers, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    PatternInitializer* initializer;
    _Vector<AdditionalInitializer>* additionalInitializers;

    virtual bool _isBindingInitializer();
};

class PatternInitializer : public SyntaxNode {
public:
    PatternInitializer(Pattern* pattern, Initializer* initializer, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Pattern* pattern;
    Initializer* initializer;

    virtual bool _isPatternInitializer();
};

class AdditionalInitializer : public SyntaxNode {
public:
    AdditionalInitializer(PatternInitializer* pattern, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    PatternInitializer* pattern;

    virtual bool _isAdditionalInitializer();
};

class Modifier : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isModifier();
    virtual bool _isOverrideWord();
    virtual bool _isStaticWord();
};

class OverrideWord : public Modifier {
public:
    OverrideWord(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isOverrideWord();
};

class StaticWord : public Modifier {
public:
    StaticWord(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isStaticWord();
};

class FunctionSignature : public SyntaxNode {
public:
    FunctionSignature(ParameterClause* parameterClause, FunctionResult* result, ThrowsClause* throwsClause, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    ParameterClause* parameterClause;
    FunctionResult* result;
    ThrowsClause* throwsClause;

    virtual bool _isFunctionSignature();
};

class FunctionResult : public SyntaxNode {
public:
    FunctionResult(Type* resultType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* resultType;

    virtual bool _isFunctionResult();
};

class ParameterClause : public SyntaxNode {
public:
    ParameterClause(_Vector<Parameter>* parameters, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<Parameter>* parameters;

    virtual bool _isParameterClause();
};

class Parameter : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isParameter();
    virtual bool _isConstParameter();
    virtual bool _isVarParameter();
};

class ConstParameter : public Parameter {
public:
    ConstParameter(string* name, Type* parameterType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;
    Type* parameterType;

    virtual bool _isConstParameter();
};

class VarParameter : public Parameter {
public:
    VarParameter(string* name, Type* parameterType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;
    Type* parameterType;

    virtual bool _isVarParameter();
};

class ThrowsClause : public SyntaxNode {
public:
    ThrowsClause(Type* throwsType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* throwsType;

    virtual bool _isThrowsClause();
};

class EnumMember : public SyntaxNode {
public:
    EnumMember(EnumCase* enumCase, _Vector<AdditionalCase>* additionalCases, ParameterClause* parameterClause, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    EnumCase* enumCase;
    _Vector<AdditionalCase>* additionalCases;
    ParameterClause* parameterClause;

    virtual bool _isEnumMember();
};

class EnumCase : public SyntaxNode {
public:
    EnumCase(string* name, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;

    virtual bool _isEnumCase();
};

class AdditionalCase : public SyntaxNode {
public:
    AdditionalCase(EnumCase* enumCase, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    EnumCase* enumCase;

    virtual bool _isAdditionalCase();
};

class ClassBody : public SyntaxNode {
public:
    ClassBody(_Vector<ClassMember>* members, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<ClassMember>* members;

    virtual bool _isClassBody();
};

class ClassMember : public SyntaxNode {
public:
    ClassMember(Declaration* declaration, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Declaration* declaration;

    virtual bool _isClassMember();
};

class PrefixExpression : public SyntaxNode {
public:
    PrefixExpression(string* prefixOperator, PostfixExpression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* prefixOperator;
    PostfixExpression* expression;

    virtual bool _isPrefixExpression();
};

class PostfixExpression : public SyntaxNode {
public:
    PostfixExpression(PrimaryExpression* primaryExpression, _Vector<Postfix>* postfixes, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    PrimaryExpression* primaryExpression;
    _Vector<Postfix>* postfixes;

    virtual bool _isPostfixExpression();
};

class BinaryOp : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isBinaryOp();
    virtual bool _isBinaryOperation();
    virtual bool _isAssignment();
    virtual bool _isTypeQuery();
    virtual bool _isTypeCast();
};

class BinaryOperation : public BinaryOp {
public:
    BinaryOperation(string* binaryOperator, PrefixExpression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* binaryOperator;
    PrefixExpression* expression;

    virtual bool _isBinaryOperation();
};

class Assignment : public BinaryOp {
public:
    Assignment(Expression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* expression;

    virtual bool _isAssignment();
};

class TypeQuery : public BinaryOp {
public:
    TypeQuery(Type* objectType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* objectType;

    virtual bool _isTypeQuery();
};

class TypeCast : public BinaryOp {
public:
    TypeCast(Type* objectType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* objectType;

    virtual bool _isTypeCast();
};

class CatchClause : public SyntaxNode {
public:
    CatchClause(CatchPattern* catchPattern, TuplePattern* bindingPattern, Expression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    CatchPattern* catchPattern;
    TuplePattern* bindingPattern;
    Expression* expression;

    virtual bool _isCatchClause();
};

class CatchPattern : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isCatchPattern();
    virtual bool _isWildCardCatchPattern();
    virtual bool _isIdentifierCatchPattern();
};

class WildCardCatchPattern : public CatchPattern {
public:
    WildCardCatchPattern(WildcardPattern* pattern, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    WildcardPattern* pattern;

    virtual bool _isWildCardCatchPattern();
};

class IdentifierCatchPattern : public CatchPattern {
public:
    IdentifierCatchPattern(string* name, MemberExpression* member, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;
    MemberExpression* member;

    virtual bool _isIdentifierCatchPattern();
};

class Postfix : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isPostfix();
    virtual bool _isOperatorPostfix();
    virtual bool _isFunctionCall();
    virtual bool _isMemberExpression();
    virtual bool _isSubscript();
};

class OperatorPostfix : public Postfix {
public:
    OperatorPostfix(string* postfixOperator, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* postfixOperator;

    virtual bool _isOperatorPostfix();
};

class FunctionCall : public Postfix {
public:
    FunctionCall(ParenthesizedExpression* arguments, _Vector<CatchClause>* catchClauses, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    ParenthesizedExpression* arguments;
    _Vector<CatchClause>* catchClauses;

    virtual bool _isFunctionCall();
};

class MemberExpression : public Postfix {
public:
    MemberExpression(string* member, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* member;

    virtual bool _isMemberExpression();
};

class Subscript : public Postfix {
public:
    Subscript(_Vector<ExpressionElement>* expressions, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<ExpressionElement>* expressions;

    virtual bool _isSubscript();
};

class ExpressionElement : public SyntaxNode {
public:
    ExpressionElement(Expression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* expression;

    virtual bool _isExpressionElement();
};

class PrimaryExpression : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isPrimaryExpression();
    virtual bool _isIdentifierExpression();
    virtual bool _isLiteralExpression();
    virtual bool _isIfExpression();
    virtual bool _isSwitchExpression();
    virtual bool _isForExpression();
    virtual bool _isWhileExpression();
    virtual bool _isDoExpression();
    virtual bool _isParenthesizedExpression();
    virtual bool _isReturnExpression();
    virtual bool _isThrowExpression();
    virtual bool _isBreakExpression();
    virtual bool _isConstructorCall();
    virtual bool _isThisExpression();
    virtual bool _isNullExpression();
};

class IdentifierExpression : public PrimaryExpression {
public:
    IdentifierExpression(string* name, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;

    virtual bool _isIdentifierExpression();
};

class LiteralExpression : public PrimaryExpression {
public:
    LiteralExpression(Literal* literal, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Literal* literal;

    virtual bool _isLiteralExpression();
};

class IfExpression : public PrimaryExpression {
public:
    IfExpression(Expression* condition, Expression* consequent, ElseClause* elseClause, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* condition;
    Expression* consequent;
    ElseClause* elseClause;

    virtual bool _isIfExpression();
};

class SwitchExpression : public PrimaryExpression {
public:
    SwitchExpression(Expression* expression, SwitchBody* body, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* expression;
    SwitchBody* body;

    virtual bool _isSwitchExpression();
};

class ForExpression : public PrimaryExpression {
public:
    ForExpression(Pattern* pattern, Expression* expression, Expression* code, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Pattern* pattern;
    Expression* expression;
    Expression* code;

    virtual bool _isForExpression();
};

class WhileExpression : public PrimaryExpression {
public:
    WhileExpression(Expression* condition, Expression* code, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* condition;
    Expression* code;

    virtual bool _isWhileExpression();
};

class DoExpression : public PrimaryExpression {
public:
    DoExpression(Expression* code, Expression* condition, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* code;
    Expression* condition;

    virtual bool _isDoExpression();
};

class ParenthesizedExpression : public PrimaryExpression {
public:
    ParenthesizedExpression(_Vector<ExpressionElement>* expressionElements, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<ExpressionElement>* expressionElements;

    virtual bool _isParenthesizedExpression();
};

class ReturnExpression : public PrimaryExpression {
public:
    ReturnExpression(ParenthesizedExpression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    ParenthesizedExpression* expression;

    virtual bool _isReturnExpression();
};

class ThrowExpression : public PrimaryExpression {
public:
    ThrowExpression(IdentifierExpression* error, ParenthesizedExpression* arguments, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    IdentifierExpression* error;
    ParenthesizedExpression* arguments;

    virtual bool _isThrowExpression();
};

class BreakExpression : public PrimaryExpression {
public:
    BreakExpression(ParenthesizedExpression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    ParenthesizedExpression* expression;

    virtual bool _isBreakExpression();
};

class ConstructorCall : public PrimaryExpression {
public:
    ConstructorCall(Type* typeToInitialize, ParenthesizedExpression* arguments, _Vector<CatchClause>* catchClauses, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* typeToInitialize;
    ParenthesizedExpression* arguments;
    _Vector<CatchClause>* catchClauses;

    virtual bool _isConstructorCall();
};

class ThisExpression : public PrimaryExpression {
public:
    ThisExpression(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isThisExpression();
};

class NullExpression : public PrimaryExpression {
public:
    NullExpression(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isNullExpression();
};

class ElseClause : public SyntaxNode {
public:
    ElseClause(Expression* alternative, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* alternative;

    virtual bool _isElseClause();
};

class SwitchBody : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isSwitchBody();
    virtual bool _isCurliedSwitchBody();
    virtual bool _isNakedSwitchBody();
};

class CurliedSwitchBody : public SwitchBody {
public:
    CurliedSwitchBody(_Vector<SwitchCase>* cases, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<SwitchCase>* cases;

    virtual bool _isCurliedSwitchBody();
};

class NakedSwitchBody : public SwitchBody {
public:
    NakedSwitchBody(_Vector<SwitchCase>* cases, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<SwitchCase>* cases;

    virtual bool _isNakedSwitchBody();
};

class SwitchCase : public SyntaxNode {
public:
    SwitchCase(CaseLabel* label, CaseContent* content, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    CaseLabel* label;
    CaseContent* content;

    virtual bool _isSwitchCase();
};

class CaseLabel : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isCaseLabel();
    virtual bool _isItemCaseLabel();
    virtual bool _isDefaultCaseLabel();
};

class ItemCaseLabel : public CaseLabel {
public:
    ItemCaseLabel(Pattern* pattern, _Vector<CaseItem>* additionalPatterns, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Pattern* pattern;
    _Vector<CaseItem>* additionalPatterns;

    virtual bool _isItemCaseLabel();
};

class DefaultCaseLabel : public CaseLabel {
public:
    DefaultCaseLabel(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isDefaultCaseLabel();
};

class CaseItem : public SyntaxNode {
public:
    CaseItem(Pattern* pattern, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Pattern* pattern;

    virtual bool _isCaseItem();
};

class Pattern : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isPattern();
    virtual bool _isWildcardPattern();
    virtual bool _isIdentifierPattern();
    virtual bool _isTuplePattern();
    virtual bool _isExpressionPattern();
};

class WildcardPattern : public Pattern {
public:
    WildcardPattern(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isWildcardPattern();
};

class IdentifierPattern : public Pattern {
public:
    IdentifierPattern(string* identifier, TypeAnnotation* annotationForType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* identifier;
    TypeAnnotation* annotationForType;

    virtual bool _isIdentifierPattern();
};

class TuplePattern : public Pattern {
public:
    TuplePattern(_Vector<TuplePatternElement>* elements, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<TuplePatternElement>* elements;

    virtual bool _isTuplePattern();
};

class ExpressionPattern : public Pattern {
public:
    ExpressionPattern(Expression* expression, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Expression* expression;

    virtual bool _isExpressionPattern();
};

class TuplePatternElement : public SyntaxNode {
public:
    TuplePatternElement(Pattern* pattern, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Pattern* pattern;

    virtual bool _isTuplePatternElement();
};

class CaseContent : public SyntaxNode {
public:
    CaseContent(_Vector<Statement>* statements, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<Statement>* statements;

    virtual bool _isCaseContent();
};

class Type : public SyntaxNode {
public:
    Type(string* name, Subtype* subType, _Vector<TypePostfix>* postfixes, LifeTime* region, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    string* name;
    Subtype* subType;
    _Vector<TypePostfix>* postfixes;
    LifeTime* region;

    virtual bool _isType();
};

class TypeAnnotation : public SyntaxNode {
public:
    TypeAnnotation(Type* annotationForType, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* annotationForType;

    virtual bool _isTypeAnnotation();
};

class Subtype : public SyntaxNode {
public:
    Subtype(Type* type, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* type;

    virtual bool _isSubtype();
};

class TypePostfix : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isTypePostfix();
    virtual bool _isIndexedType();
    virtual bool _isPointer();
};

class IndexedType : public TypePostfix {
public:
    IndexedType(Type* key, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* key;

    virtual bool _isIndexedType();
};

class Pointer : public TypePostfix {
public:
    Pointer(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isPointer();
};

class LifeTime : public SyntaxNode {
public:
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isLifeTime();
    virtual bool _isLocal();
    virtual bool _isReference();
    virtual bool _isThrown();
};

class Local : public LifeTime {
public:
    Local(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isLocal();
};

class Reference : public LifeTime {
public:
    Reference(Literal* age, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Literal* age;

    virtual bool _isReference();
};

class Thrown : public LifeTime {
public:
    Thrown(Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);

    virtual bool _isThrown();
};

class TypeInheritanceClause : public SyntaxNode {
public:
    TypeInheritanceClause(_Vector<Inheritance>* inheritances, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    _Vector<Inheritance>* inheritances;

    virtual bool _isTypeInheritanceClause();
};

class Inheritance : public SyntaxNode {
public:
    Inheritance(Type* type, Position* start, Position* end);
    virtual void accept(SyntaxVisitor* visitor);
    Type* type;

    virtual bool _isInheritance();
};

}
#endif // __scalyc__Syntax__
